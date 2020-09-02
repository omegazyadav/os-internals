// Message passing mechanism for multithreaded concurrency 
// Here mpsc is a 'multiple producer, single consumer' which 
// takes the ownership of 'val' and send it to the single consumer
// whcich is tx. 


use std::sync::mpsc;
use std::thread;

fn main() {
    let (tx, rx) = mpsc::channel();

    thread::spawn(move || {
        let val = String::from("hi");
        tx.send(val).unwrap();
    });


    let received = rx.recv().unwrap();
    println!("Got: {}",received);
}
