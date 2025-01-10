import requests

# Replace with your LeetCode username
USERNAME = "ViLeIUH185"
LEETCODE_API_URL = "https://leetcode.com/graphql"
README_FILE = "README.md"

# GraphQL query to fetch LeetCode stats
query = """
query {
  matchedUser(username: "%s") {
    username
    submitStats {
      acSubmissionNum {
        difficulty
        count
      }
    }
  }
}
""" % USERNAME

# Fetch data from LeetCode
def fetch_leetcode_stats():
    response = requests.post(
        LEETCODE_API_URL,
        json={"query": query},
        headers={"Content-Type": "application/json"}
    )
    if response.status_code == 200:
        return response.json()["data"]["matchedUser"]["submitStats"]["acSubmissionNum"]
    else:
        print(f"Error: {response.status_code} - {response.text}")
        return None

# Update README.md with stats
def update_readme(stats):
    total = stats[0]["count"]
    easy = stats[1]["count"]
    medium = stats[2]["count"]
    hard = stats[3]["count"]

    with open(README_FILE, "r") as file:
        lines = file.readlines()

    # Insert stats into README.md
    start_index = None
    end_index = None
    for i, line in enumerate(lines):
        if line.strip() == "<!-- LEETCODE_STATS_START -->":
            start_index = i
        elif line.strip() == "<!-- LEETCODE_STATS_END -->":
            end_index = i

    if start_index is not None and end_index is not None:
        stats_content = (
            f"**LeetCode Stats**:\n\n"
            f"- Total Problems Solved: {total}\n"
            f"- Easy: {easy}\n"
            f"- Medium: {medium}\n"
            f"- Hard: {hard}\n"
        )
        lines[start_index + 1 : end_index] = [stats_content]

    with open(README_FILE, "w") as file:
        file.writelines(lines)

# Main
if __name__ == "__main__":
    stats = fetch_leetcode_stats()
    if stats:
        update_readme(stats)
