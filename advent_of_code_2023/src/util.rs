use std::{
    fs::File,
    io::{BufRead, BufReader},
};

pub fn file_reader(file_name: String) -> Result<Vec<String>, std::io::Error> {
    let mut path = std::env::current_dir().expect("can't find current working diretory");
    path.push("reference");
    path.push(file_name);
    let file = File::open(path).expect("fail to open");
    let reader = BufReader::new(file);

    let contents: Vec<String> = reader
        .lines()
        .into_iter()
        .map(|res| res.expect(""))
        .collect();

    Ok(contents)
}
