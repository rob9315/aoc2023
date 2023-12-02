if [ ! -d "$1" ] ; then
    echo "please supply which task should be measured"
    exit 1
fi
if [ ! "$2" = "first" ] && [ ! "$2" = "second" ] ; then
    echo "please choose first or second"
    exit 1
fi
if [ ! -f "$1/input.txt" ] ; then
    echo "please provide $1/input.txt"
    exit 1
fi

cd "$1"

[ -f "js/$2.js" ] && echo "==JS==" && cat input.txt | time deno run "js/$2.js"
[ -f "rs/src/bin/$1$2.rs" ] && cargo build --release --bin "$1$2" -q && echo "==RS==" && cat input.txt | time "../target/release/$1$2"
[ -f "cpp/$2.cpp" ] && g++ "cpp/$2.cpp" -o "cpp/$2.out" && echo "==CPP==" && cat input.txt | time "cpp/$2.out"
