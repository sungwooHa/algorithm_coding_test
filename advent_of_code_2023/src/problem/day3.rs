use core::panic;
use std::{collections::HashMap, fmt::Error, hash::Hash};

use crate::{solution::Solution, util};

pub struct Day3 {}

fn convert_priority(compartments : char) -> u32 {
    if compartments.is_uppercase() {
        compartments as u32 - 'A' as u32 + 27
    }else {
        compartments as u32 - 'a' as u32 + 1
    }
}

impl Solution for Day3 {
    fn solve1() -> Result<String, std::io::Error> {
        let input = util::file_reader("day3.txt".to_string())?;

        let mut sum: u32 = 0;
        for line in input {
            let first = &line[0..line.len() >> 1];
            let second = &line[line.len() >> 1..line.len()];

            let map: HashMap<char, _> = first.chars().map(|char| (char, true)).collect();
            let res: Vec<_> = second
                .chars()
                .filter(|char| map.get(char).is_some())
                //.map(|char| char as u32)
                .collect();

            sum += convert_priority(res[0]);
        }

        println!("result : {}", sum);
        Ok("ok".to_string())
    }

    fn solve2() -> Result<String, std::io::Error> {
        let input = util::file_reader("day3.txt".to_string())?;

        let mut sum: u32 = 0;
        let result = match IntoIterator::into_iter(input) {


            mut iter => loop {
                let mut next;
                match iter.next() {
                    Some(val) => next = val,
                    None => break,
                };
                let res : HashMap<char, _> = next.chars().map(|char| (char, true)).collect();
                
                match iter.next() {
                    Some(val) => next = val,
                    None => break,
                };

                let res: HashMap<char, _> = next
                    .chars()
                    .map(|char| (char, true))
                    .filter(|(char, _)| res.get(char).is_some())
                    .collect();

                    match iter.next() {
                        Some(val) => next = val,
                        None => break,
                    };

                    let res: Vec<_> = next
                    .chars()
                    .filter(|char| res.get(char).is_some())
                    //.map(|char| char as u32)
                    .collect();

                    sum += convert_priority(res[0]);
            },
        };

        println!("{:?}", sum);


        // for line in input {
            
        //     let first = &line[0..line.len() >> 1];
        //     let second = &line[line.len() >> 1..line.len()];

        //     let map: HashMap<char, _> = first.chars().map(|char| (char, true)).collect();
        //     let res: Vec<_> = second
        //         .chars()
        //         .filter(|char| map.get(char).is_some())
        //         //.map(|char| char as u32)
        //         .collect();

        //     sum += convert_priority(res[0]);
        // }

        Ok("ok".to_string())
    }
}
