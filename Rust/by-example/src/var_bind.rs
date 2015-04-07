/// Usage of bindings
pub fn _run() {
    // prepending with underscore disables compiler warnings about unused
    // variables.  Seems to work with functions as well.
    let _unit = ();

    let mut mutable = 1;
    mutable += 1;

    let shadow = 1;
    {
        let shadow = 3;
        println!("shadow {}, is in code block.", shadow);
    }
    println!("shadow {}, is outside code block.", shadow);

    //  y is uninitialized and cannot be used until it is.
    let y;
}
