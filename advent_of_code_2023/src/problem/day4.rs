use core::panic;
use std::{collections::HashMap, fmt::Error, hash::Hash};

use crate::{solution::Solution, util};

pub struct Day4 {}

struct Range {
    start: usize,
    end: usize,
}

impl Range {
    fn is_contain(&self, rhs: &Range) -> bool {
        self.start <= rhs.start && self.end >= rhs.end
    }

    //  345
    //123
    fn is_overapping(&self, rhs: &Range) -> bool {
        self.end >= rhs.start && self.start <= rhs.start 
        || self.end >= rhs.end && self.start <= rhs.end
    }

    pub fn make_range(range: &str) -> Range {
        let range: Vec<usize> = range
            .split("-")
            .map(|numb| numb.parse::<usize>().unwrap())
            .collect();
        Range {
            start: range.get(0).unwrap().clone(),
            end: range.get(1).unwrap().clone(),
        }
    }
}

impl Day4 {}

impl Solution for Day4 {
    fn solve1() -> Result<String, std::io::Error> {
        let input = util::file_reader("day4.txt".to_string())?;

        let mut contains_resutl = 0;
        for line in input {
            let ranges: Vec<Range> = line
                .split(",")
                .map(|range| Range::make_range(range))
                .collect();

            if ranges[0].is_contain(&ranges[1]) {
                contains_resutl += 1;
            } else if ranges[1].is_contain(&ranges[0]) {
                contains_resutl += 1;
            }
        }

        println!("number of contrains : {}", contains_resutl);
        Ok("sovle1".to_string())
    }

    fn solve2() -> Result<String, std::io::Error> {
        let input = util::file_reader("day4.txt".to_string())?;

        let mut overapping_result = 0;

        for line in input {
            let ranges: Vec<Range> = line
                .split(",")
                .map(|range| Range::make_range(range))
                .collect();

            if ranges[0].is_overapping(&ranges[1]) {
                overapping_result += 1;
            }else             if ranges[1].is_overapping(&ranges[0]) {
                overapping_result += 1;
            }
        }

        println!("number of overapping : {}", overapping_result);
        Ok("sovle2".to_string())
    }
}
