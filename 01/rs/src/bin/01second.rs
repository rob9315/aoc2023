/*
 * Compile using cargo
 * 
 * $ cargo build --release --bin 01first
 * 
 * Run directly
 * 
 * $ cat input.txt | time ../target/release/01second
 */

fn main() {
    let mut s = String::new();
    let mut n: i32 = 0;
    while std::io::stdin().read_line(&mut s).is_ok() {
        let Some(fc) = (0..s.len() - 1)
            .flat_map(|a| s.get(a..))
            .flat_map(|s| substr_num(|teststr| s.starts_with(teststr)))
            .next() else { break };
        let lc = (1..s.len())
            .rev()
            .flat_map(|a| s.get(..a))
            .flat_map(|s| substr_num(|teststr| s.ends_with(teststr)))
            .next()
            .expect("how");
        n += fc * 10;
        n += lc;

        s.clear();
    }

    println!("{}", n);
}

fn substr_num(f: impl Fn(&str) -> bool) -> Option<i32> {
    const MAPPING: [(&str, i32); 19] = [
        ("0", 0),
        ("1", 1),
        ("2", 2),
        ("3", 3),
        ("4", 4),
        ("5", 5),
        ("6", 6),
        ("7", 7),
        ("8", 8),
        ("9", 9),
        ("one", 1),
        ("two", 2),
        ("three", 3),
        ("four", 4),
        ("five", 5),
        ("six", 6),
        ("seven", 7),
        ("eight", 8),
        ("nine", 9),
    ];
    for (s, n) in MAPPING {
        if f(s) {
            return Some(n);
        }
    }
    None
}
