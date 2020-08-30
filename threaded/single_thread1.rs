// Simple threaded program in rust 
// This program consist of one spawned thread and the main thread in which 
// execution of the thread and main thread happens simultaneusly but when the 
// main therad loop finishes then spawned thread also terminates. 

use std::thread;
use std::time::Duration;

fn main() {
    thread::spawn(|| {
        for i in 1..10 {
            println!("hi number {} from the spawned thread!", i);
            thread::sleep(Duration::from_millis(1));
        }
    });

    for i in 1..5 {
        println!("hi number {} from the main thread!", i);
        thread::sleep(Duration::from_millis(1));
    }
}
