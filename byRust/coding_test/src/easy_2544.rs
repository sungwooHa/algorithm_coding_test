fn analyze(n: i32) -> Vec<i32> {
    n.to_string()
        .chars()
        .map(|val| val.to_string().parse::<i32>().unwrap())
        .collect::<Vec<i32>>()
}

pub fn alternate_digit_sum(n: i32) -> i32 {
    let mut result: i32 = 0;
    analyze(n).into_iter().enumerate().for_each(|(index, val)| {
        result += if index % 2 == 0 { val } else { -val };
    });

    result
}
