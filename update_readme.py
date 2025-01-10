import requests
import matplotlib.pyplot as plt
import numpy as np
import os

# Replace with your LeetCode username
USERNAME = "ViLeIUH185"
LEETCODE_API_URL = "https://leetcode.com/graphql"
README_FILE = "README.md"

# GraphQL query to fetch LeetCode stats
def build_query(username):
    return (
        f"""
query {{
  matchedUser(username: "{username}") {{
    username
    profile {{
      reputation
      ranking
    }}
    submitStats {{
      acSubmissionNum {{
        difficulty
        count
      }}
      totalSubmissionNum {{
        difficulty
        submissions
      }}
    }}
    languageProblemCount {{
      languageName
      problemsSolved
    }}
  }}
  allQuestionsCount {{
    difficulty
    count
  }}
}}
"""
    )

# Fetch data from LeetCode
def fetch_leetcode_stats(username):
    query = build_query(username)
    response = requests.post(
        LEETCODE_API_URL,
        json={"query": query},
        headers={"Content-Type": "application/json"},
    )
    if response.status_code == 200:
        data = response.json().get("data", {})
        if not data.get("matchedUser"):
            raise ValueError(f"User '{username}' not found or data unavailable.")
        return data["matchedUser"], data["allQuestionsCount"]
    else:
        raise Exception(f"Error: {response.status_code} - {response.text}")

# Generate column chart for data
def generate_chart(data, title, filename):
    labels = [item["languageName"] for item in data]
    sizes = [item["problemsSolved"] for item in data]

    if not labels or not sizes:
        print(f"No data available for chart: {title}")
        return

    x = np.arange(len(labels))  # Label locations
    width = 0.35  # Bar width

    plt.figure(figsize=(10, 6))
    plt.bar(x, sizes, width, label="Problems Solved")
    plt.xlabel("Languages")
    plt.ylabel("Problems Solved")
    plt.title(title)
    plt.xticks(x, labels, rotation=45, ha="right")
    plt.tight_layout()
    plt.savefig(filename)
    plt.close()

# Generate column chart for problem difficulties
def generate_difficulty_chart(data, total_counts, title, filename):
    labels = [item["difficulty"] for item in data]
    solved = [item["count"] for item in data]
    totals = [total_counts.get(diff["difficulty"], 0) for diff in data]

    x = np.arange(len(labels))  # Label locations
    width = 0.35  # Bar width

    plt.figure(figsize=(10, 6))
    plt.bar(x - width / 2, solved, width, label="Solved Problems")
    plt.bar(x + width / 2, totals, width, label="Total Problems")
    plt.xlabel("Difficulty")
    plt.ylabel("Number of Problems")
    plt.title(title)
    plt.xticks(x, labels)
    plt.legend()
    plt.tight_layout()
    plt.savefig(filename)
    plt.close()

# Update README.md with stats
def update_readme(stats, total_counts):
    ac_stats = stats["submitStats"]["acSubmissionNum"]
    languages = stats["languageProblemCount"]
    profile = stats["profile"]

    total_problems = ac_stats[0]["count"]
    easy = ac_stats[1]["count"]
    medium = ac_stats[2]["count"]
    hard = ac_stats[3]["count"]

    total_counts_dict = {item["difficulty"]: item["count"] for item in total_counts}

    generate_chart(
        languages, "LeetCode Problems Solved by Language", "leetcode_languages.png"
    )
    generate_difficulty_chart(
        ac_stats,
        total_counts_dict,
        "LeetCode Problem Solving by Difficulty",
        "leetcode_difficulties.png",
    )

    stats_content = (
        f"**LeetCode Stats**:\n\n"
        f"**User Profile Information:**\n"
        f"- Username: {stats['username']}\n"
        f"- Total Problems Solved: {total_problems}\n"
        f"- Ranking: {profile['ranking']}\n"
        f"- Reputation: {profile['reputation']}\n\n"
        f"**Problems Information:**\n"
        f"- Easy: {easy}/{total_counts_dict.get('Easy', 0)}\n"
        f"- Medium: {medium}/{total_counts_dict.get('Medium', 0)}\n"
        f"- Hard: {hard}/{total_counts_dict.get('Hard', 0)}\n\n"
        f"**Coding Languages and Runtime Information:**\n"
        + "\n".join(
            [
                f"- {lang['languageName']}: {lang['problemsSolved']} problems"
                for lang in languages
            ]
        )
        + "\n\n"
        f"![Problems by Language](./leetcode_languages.png)\n"
        f"![Problem Difficulties](./leetcode_difficulties.png)\n"
    )

    if os.path.exists(README_FILE):
        with open(README_FILE, "r") as file:
            lines = file.readlines()

        start_index = None
        end_index = None
        for i, line in enumerate(lines):
            if line.strip() == "<!-- LEETCODE_STATS_START -->":
                start_index = i
            elif line.strip() == "<!-- LEETCODE_STATS_END -->":
                end_index = i

        if start_index is not None and end_index is not None:
            lines[start_index + 1 : end_index] = [stats_content + "\n"]

        with open(README_FILE, "w") as file:
            file.writelines(lines)
    else:
        with open(README_FILE, "w") as file:
            file.write("<!-- LEETCODE_STATS_START -->\n")
            file.write(stats_content)
            file.write("\n<!-- LEETCODE_STATS_END -->\n")

# Main
if __name__ == "__main__":
    try:
        stats, total_counts = fetch_leetcode_stats(USERNAME)
        if stats and total_counts:
            update_readme(stats, total_counts)
    except Exception as e:
        print(f"Error: {e}")
