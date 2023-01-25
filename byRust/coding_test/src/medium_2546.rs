fn count_ones(s: String) -> usize {
    s.chars().filter(|c| *c == '1').count()
}

pub fn make_strings_equal(s: String, target: String) -> bool {
    let s = count_ones(s);
    let target = count_ones(target);
    if s == 0 {
        target == 0
    } else {
        target >= 1
    }
}