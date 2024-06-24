function buildArray(array) {
    const multiplier = 100000;
    for (let index = 0; index < array.length; index++) {
        const currentNumber = array[index];
        let numberToPut = array[array[index]];
        if (numberToPut > 999) {
            numberToPut = numberToPut % multiplier;
        }
        array[index] = multiplier * numberToPut + currentNumber;
    }
    for (let index = 0; index < array.length; index++) {
        if (array[index] <= 999) {
            array[index] = 0;
        } else {
            array[index] = parseInt(array[index] / multiplier);
        }
    }
    return array;
}

// Main function to demonstrate usage
function main() {
    // Test case 1
    let array1 = [0, 2, 1, 5, 3, 4];
    let result1 = buildArray(array1);
    console.log("Processed array:", result1);
}

// Calling main function to execute tests
main();