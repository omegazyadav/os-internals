// Move closure with thread 
// Activities in between threads can be bogus when same variable 
// are shared among them, on such case rust handles the ownership 
// of vairables with the help of move closure.  Here the newly created
// thread has the ownership of the vector 'v'. 


use std::thread;

fn main() {
    let v = vec![1, 2, 3];

    let handle = thread::spawn(move || {
        println!("Here's a vector: {:?}", v);
    });

    handle.join().unwrap();
}
