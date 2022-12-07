use core::panic;
use std::{fmt::Error, vec};
use strum::{IntoEnumIterator, EnumIter};

use crate::{solution::Solution, util};

#[derive(PartialEq, Debug, EnumIter)]
enum GameResult {
    win,
    draw,
    lose,
    invalid,
}

impl GameResult {
    fn game_result_to_score(&self) -> usize {
        match self {
            GameResult::win => 6,
            GameResult::draw => 3,
            GameResult::lose => 0,
            GameResult::invalid => 0,
        }
    }

    fn need_game_result(str :&str) -> GameResult {
        match str {
            "X" => GameResult::lose, //lose
            "Y" => GameResult::draw, //draw
            "Z" => GameResult::win, //win
            _ => GameResult::invalid,
        }
    }
}

#[derive(PartialEq, Debug, EnumIter)]
enum GameType {
    Rock,
    Paper,
    Scissors,
    invalid,
}

fn find_opponent_game_type(game_result : &GameResult, my_game_type: &GameType) -> GameType {
    for game_type in GameType::iter().collect::<Vec<_>>() {
        if my_game_type.fight(&game_type).eq(game_result){
            return game_type;
        }
    }
    GameType::invalid
}

fn find_my_game_type(game_result : &GameResult, opponent_game_type: &GameType) -> GameType {
    for game_type in GameType::iter().collect::<Vec<_>>() {
        if game_type.fight(&opponent_game_type).eq(game_result){
            return game_type;
        }
    }
    GameType::invalid
}


impl GameType {
    fn fight(&self, opponent_game_type: &GameType) -> GameResult {
        match self {
            GameType::Rock => match opponent_game_type {
                GameType::Rock => GameResult::draw,
                GameType::Paper => GameResult::lose,
                GameType::Scissors => GameResult::win,
                GameType::invalid => GameResult::invalid,
            },
            GameType::Paper => match opponent_game_type {
                GameType::Rock => GameResult::win,
                GameType::Paper => GameResult::draw,
                GameType::Scissors => GameResult::lose,
                GameType::invalid => GameResult::invalid,
            },
            GameType::Scissors => match opponent_game_type {
                GameType::Rock => GameResult::lose,
                GameType::Paper => GameResult::win,
                GameType::Scissors => GameResult::draw,
                GameType::invalid => GameResult::invalid,
            },
            _ => GameResult::invalid,
        }
    }

    pub fn my_str_to_game_type(str: &str) -> GameType {
        match str {
            "X" => GameType::Rock, //lose
            "Y" => GameType::Paper, //draw
            "Z" => GameType::Scissors, //win
            _ => GameType::invalid,
        }
    }

    pub fn opponent_str_to_game_type(str: &str) -> GameType {
        match str {
            "A" => GameType::Rock,
            "B" => GameType::Paper,
            "C" => GameType::Scissors,
            _ => GameType::invalid,
        }
    }

    fn game_type_to_score(&self) -> usize {
        match self {
            GameType::Rock => 1,
            GameType::Paper => 2,
            GameType::Scissors => 3,
            GameType::invalid => 0,
        }
    }
}

fn calc_my_score(opponent_game_type: &GameType, my_game_type: &GameType) -> usize {
    my_game_type
        .fight(opponent_game_type)
        .game_result_to_score() + my_game_type.game_type_to_score()
}

pub struct Day2 {}

impl Solution for Day2 {
    fn solve1() -> Result<String, std::io::Error> {
        let input = util::file_reader("day2.txt".to_string())?;

        let mut total_score = 0;
        for line in input {
            let opponent_game_type = GameType::opponent_str_to_game_type(line.chars().nth(0).unwrap().to_string().as_str());
            let my_game_type = GameType::my_str_to_game_type(line.chars().nth(2).unwrap().to_string().as_str());

            if opponent_game_type == GameType::invalid || my_game_type==GameType::invalid {
                assert!(false);
            }

            total_score += calc_my_score(&opponent_game_type, &my_game_type);
        }

        println!("{}", total_score);
        Ok("sovle1".to_string())
    }

    fn solve2() -> Result<String, std::io::Error> {
        let input = util::file_reader("day2.txt".to_string())?;

        let mut total_score = 0;
        for line in input {
            let opponent_game_type = GameType::opponent_str_to_game_type(line.chars().nth(0).unwrap().to_string().as_str());
            let need_game_result = GameResult::need_game_result(line.chars().nth(2).unwrap().to_string().as_str());

            if opponent_game_type == GameType::invalid || need_game_result == GameResult::invalid {
                assert!(false);
            }

            total_score += &need_game_result.game_result_to_score() + find_my_game_type(&need_game_result, &opponent_game_type).game_type_to_score();
        }

        println!("{}", total_score);
        Ok("sovle2".to_string())
    }
}
