// write a function that takes the input string and reverses it
function reverseString(string) {
  string = string.split("");
  string = string.reverse();
  string = string.join("");
  return string;
}
console.log(reverseString("XYZ"));

// write a function that takes the input string and switches all
// uppercase characters to lowercase and lowercase charcaters to uppercase
function swapCase(string) {
  let swappedString = "";
  for (let i = 0; i < string.length; i++) {
    if (string[i] === string.toUpperCase()[i]) {
      swappedString += string.toLowerCase()[i];
    } else {
      swappedString += string.toUpperCase()[i];
    }
  }
  return swappedString;
}
console.log(swapCase("all caps NO CAPS"));

//convert array of numbers from farenheit to celcius
function toCelsius(value) {
  //   let conversion = (5 / 9) * (value - 32);
  //   return conversion;
  let conversion = value.map((x) => (5 / 9) * (x - 32));
  return conversion;
}
let array = [32, 41, 68, 77, 86];
// console.log(array.map(toCelsius));
console.log(toCelsius(array));

//write a function that takes an input array and returns an array of booleans (>=75) or fail (<75)
function passOrFail(array) {
  //   let pass = false;
  //   if (array >= 75) {
  //     pass = true;
  //   }
  let pass = array.map((x) => x >= 75);
  return pass;
}
let grades = [75, 74, 99, 60, 83];
//console.log(grades.map(passOrFail));
console.log(passOrFail(grades));

//write code that loops through the two variables returns an array
// ['2 is zwei', '3 is drei', '4 is vier', '5 is fünf', '6 is sechs']
function germanNumbers() {
  const cardinalNumbers = [2, 3, 4, 5, 6];
  const germanNumbers = ["zwei", "drei", "vier", "fünf", "sechs"];
  const result = [];
  for (let i = 0; i < cardinalNumbers.length; i++) {
    result[i] = `${cardinalNumbers[i]} is ${germanNumbers[i]}`;
  }
  return result;
}
console.log(germanNumbers());

// write code that returns an array of ONLY prime numbers that are in the array numbers
function returnPrimes() {
  const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15];
  const primes = numbers.filter((x) => {
    for (let i = 2; i < x; i++) {
      if (x % i === 0) {
        return false;
      }
    }
    return x > 1;
  });
  return primes;
}
console.log(returnPrimes());

//Write a function that loops through and console.log's the numbers from 1 to 100,
//except multiples of three, log (without quotes) "CSC225 RULES" instead of the number,
//for the multiples of five, log (without quotes) "I LOVE JAVASCRIPT".
//For numbers which are multiples of both three and five, log (without quotes)
//"CSC225 RULES I LOVE JAVASCRIPT"
function bigLoop() {
  for (let i = 1; i <= 100; i++) {
    if (i % 3 === 0 && i % 5 == 0) {
      console.log("CSC225 RULES I LOVE JAVASCRIPT");
    } else if (i % 5 === 0) {
      console.log("I LOVE JAVASCRIPT");
    } else if (i % 3 === 0) {
      console.log("CSC225 RULES");
    } else {
      console.log(i);
    }
  }
}
bigLoop();
