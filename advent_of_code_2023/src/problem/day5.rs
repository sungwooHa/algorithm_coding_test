use std::collections::VecDeque;

use crate::{solution::Solution, util};

pub struct Day5 {}


fn command_parser(command : &String ) -> Vec<usize> {
    
    let move_info : Vec<usize> = command.split(' ').filter(|&x| x.to_string().parse::<usize>().is_ok()).map(|x| x.to_string().parse::<usize>().unwrap()).collect();
    move_info
}

impl Solution for Day5 {
    fn solve1() -> Result<String, std::io::Error> {
        
        let input = util::file_reader("day5.txt".to_string())?;

        const SIZE_VALUE_LINE: usize = 8;
        const SIZE_STACK : usize = 9;
        let mut arr_stack : Vec<VecDeque<String>> = Vec::new();
        
        for _ in 0..SIZE_STACK {
            arr_stack.push({
                let stack : VecDeque<String> = VecDeque::new();
                stack
           });
        }

        let mut line : usize = 0;
        for res in input {
            if line < SIZE_VALUE_LINE {
                for (ch_index, ch) in res.chars().enumerate().filter(|(index, ch)| (index%4) == 1 && ch.to_string() != " ".to_string() ){
                    arr_stack[(ch_index-1)/4].push_back(ch.to_string());
                }
            }
            else if line <= SIZE_VALUE_LINE + 1  {
                
            } else {
                let move_info = command_parser(&res);

                println!("{:?}", move_info);
                for _ in 0..move_info[0] {
                    let block = arr_stack[move_info[1]-1].front().unwrap().clone();
                    arr_stack[move_info[1]-1].pop_front();
                    arr_stack[move_info[2]-1].push_front(block)
                }
            }
            line += 1;
        }


        let first_block : Vec<String> = arr_stack.iter().filter(|stack| !stack.is_empty() ).map(|stack| stack.front().unwrap().clone()).collect();
        println!("{:?}", first_block);

        Ok("".to_string())
    }
    fn solve2() -> Result<String, std::io::Error> {
        
        let input = util::file_reader("day5.txt".to_string())?;

        const SIZE_VALUE_LINE: usize = 8;
        const SIZE_STACK : usize = 9;
        let mut arr_stack : Vec<VecDeque<String>> = Vec::new();
        
        for _ in 0..SIZE_STACK {
            arr_stack.push({
                let stack : VecDeque<String> = VecDeque::new();
                stack
           });
        }

        let mut line : usize = 0;
        for res in input {
            if line < SIZE_VALUE_LINE {
                for (ch_index, ch) in res.chars().enumerate().filter(|(index, ch)| (index%4) == 1 && ch.to_string() != " ".to_string() ){
                    arr_stack[(ch_index-1)/4].push_back(ch.to_string());
                }
            }
            else if line <= SIZE_VALUE_LINE + 1  {
                
            } else {
                let move_info = command_parser(&res);

                let mut tmp_stack : VecDeque<String> = VecDeque::new();
                println!("{:?}", move_info);
                for _ in 0..move_info[0] {
                    let block = arr_stack[move_info[1]-1].front().unwrap().clone();
                    tmp_stack.push_front(block);
                    arr_stack[move_info[1]-1].pop_front();
                }

                for block in tmp_stack {
                    arr_stack[move_info[2]-1].push_front(block);
                }
            }
            
            line += 1;
        }


        let first_block : Vec<String> = arr_stack.iter().filter(|stack| !stack.is_empty() ).map(|stack| stack.front().unwrap().clone()).collect();
        println!("{:?}", first_block);

        Ok("".to_string())
    }
}