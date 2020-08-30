// Simple threaded program in rust 
//
// This program is an extension of the simple_thread2.rs program. 
// In this case we observe the execution of spawned thread loop finishes 
// before the main thread. All the execution of the thread is controlled by 
// handler . 

use std::thread;
use std::time::Duration;

fn main() {
    let handle = thread::spawn(|| {
        for i in 1..10 {
            println!("hi number {} from the spawned thread!", i);
            thread::sleep(Duration::from_millis(1));
        }
    });

    handle.join().unwrap();

    for i in 1..5 {
        println!("hi number {} from the main thread!", i);
        thread::sleep(Duration::from_millis(1));
    }

}
