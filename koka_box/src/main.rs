
use wasmi::{Engine, Store, Module, Instance, Linker, Config, TypedFunc};
// use wasmtime


fn main() -> Result<(), Box<dyn std::error::Error>> {


    let wasm_bytes = include_bytes!("./code.wat");

    
    let mut config = Config::default(); 
    config.consume_fuel(true);
    
    let engine = Engine::new(&config);

    let module = Module::new(&engine, &wasm_bytes)?;

    let mut store = Store::new(&engine, ());

    store.set_fuel(1000)?;

    let instance = Instance::new(&mut store, &module, &[])?;

    let run: TypedFunc<i32, (i32, i32)> = instance.get_typed_func(&store, "run")?;

    let res = run.call(&mut store, 1)?;

    println!("Result: {} {}", res.0, res.1);

    println!("Fuel used: {}", 1000 - store.get_fuel()?);

    Ok(())

}
