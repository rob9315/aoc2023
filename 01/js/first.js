/*
 * Run using deno
 *
 * $ cat input.txt | time deno run ./js/first.js
 */

import { readLines } from "https://deno.land/std/io/mod.ts";
let t=0,z
for await (const s of readLines(Deno.stdin)) {
	if (!s) break;
	z=s.split``.filter(n=>!Number.isNaN(+n)),t+=+`${z[0]}${z[z.length-1]}`
}
console.log(t)
