/*
 * Compile using cargo
 * 
 * $ cargo build --release --bin 01first
 * 
 * Run directly
 * 
 * $ cat input.txt | time ../target/release/01first
 */

fn main() {
    let mut s = String::new();

    let fd_fun = char::is_numeric;
    let mut n: i32 = 0;
    while std::io::stdin().read_line(&mut s).is_ok() {
        let Some(fidx) = s.find(fd_fun) else { break };
        let fc = s.as_bytes().get(fidx).expect("no");
        let lc = s.as_bytes().get(s.rfind(fd_fun).expect("no")).expect("no");
        n += (fc - b'0') as i32 * 10;
        n += (lc - b'0') as i32;
        s.clear();
    }

    println!("{}", n);
}
