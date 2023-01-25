use std::collections::BTreeMap;

pub fn sort_the_students(score: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
    //k of exam
    //highest -> lowest

    let mut res = score;
    res.sort_by(|a, b| b[k as usize].cmp(&a[k as usize]));
    res
}
