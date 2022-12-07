use core::panic;
use std::fmt::Error;

use crate::{solution::Solution, util};


pub struct Day1 {}

impl Solution for Day1 {
    fn solve1() -> Result<String, std::io::Error>{
        let input = util::file_reader("day1.txt".to_string())?;
        let mut res = Vec::new();
        let mut calc : usize = 0;
        for str in input {
            if str == "" {
                res.push(calc);
                calc = 0;

                continue;
            }

            calc += str.parse::<usize>().unwrap();
        }

        res.push(calc);

        println!("{:?}", res.iter().max().unwrap());

        Ok("ok".to_string())
    }

    fn solve2() ->  Result<String, std::io::Error>{
        let input = util::file_reader("day1.txt".to_string())?;
        let mut res = Vec::new();
        let mut calc : usize = 0;
        for str in input {
            if str == "" {
                res.push(calc);
                calc = 0;

                continue;
            }

            calc += str.parse::<usize>().unwrap();
        }

        res.push(calc);

        res.sort_by(|a,b| b.partial_cmp(a).unwrap());
        println!("{:?}", res.iter().max().unwrap());

        let result = res[0] + res[1] + res[2];

        println!("res {:?}", result);

        Ok("ok".to_string())
    }
}
