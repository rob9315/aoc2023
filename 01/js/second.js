/*
 * Run using deno
 *
 * $ cat input.txt | time deno run ./js/second.js
 */

import { readLines } from "https://deno.land/std/io/mod.ts";
let t=0,z
let replacements = {
	"one": 1,
	"two": 2,
	"three": 3,
	"four": 4,
	"five": 5,
	"six": 6,
	"seven": 7,
	"eight": 8,
	"nine": 9,
};
for await (const l of readLines(Deno.stdin)) {
	if (!l) break;
	let s = l;
	for (let i = 0; i < s.length; i++) {
		let start = s.substr(0, i);
		let rest = s.substr(i);
		for (const [key, value] of Object.entries(replacements)) {
			if (rest.indexOf(key) == 0) {
				rest=rest.replace(key, value);
				i=0;
			}
		}
		s = `${start}${rest}`;
	}
	z=s.split``.filter(n=>!Number.isNaN(+n)),t+=+`${z[0]}${z[z.length-1]}`
}
console.log(t)
