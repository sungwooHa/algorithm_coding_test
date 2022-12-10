mod problem;
mod solution;
mod util;

use crate::solution::Solution;

fn main() {
    println!("Hello, world!");
    let solve1 = problem::day4::Day4::solve1();
    let solve2 = problem::day4::Day4::solve2();

    println!("{:?}", solve1);
    println!("{:?}", solve2);
}
