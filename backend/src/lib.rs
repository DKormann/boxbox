

use spacetimedb::{ReducerContext, Table};
use wasmi::{Engine, Store, Module, Instance, Linker};
use nom::IResult;


#[spacetimedb::table(name = person)]
pub struct Person {
    name: String    
}



pub fn exec_wasm() -> Result<(), Box<dyn std::error::Error>>  {
    let wasm_code = r#"
    (module
        (func (export "run")
              (nop)))
"#
;
    let wasm_bytes : &[u8] = wasm_code.as_bytes();

    let engine = Engine::default();
    let module = Module::new(&engine, &wasm_bytes)?;

    let mut store = Store::new(&engine, ());
    let instance = Instance::new(&mut store, &module, &[])?;

    let run: wasmi::TypedFunc<(), ()> = instance.get_typed_func(&store, "run")?;

    run.call(&mut store, ())?;



    Ok(())
}



#[spacetimedb::reducer(init)]   
pub fn init(_ctx: &ReducerContext) {


    // Called when the module is initially published
}

#[spacetimedb::reducer(client_connected)]
pub fn identity_connected(_ctx: &ReducerContext) {
    // Called everytime a new client connects
}

#[spacetimedb::reducer(client_disconnected)]
pub fn identity_disconnected(_ctx: &ReducerContext) {
    // Called everytime a client disconnects
}

#[spacetimedb::reducer]
pub fn add(ctx: &ReducerContext, name: String) {
    ctx.db.person().insert(Person { name });
}

#[spacetimedb::reducer]
pub fn say_hello(ctx: &ReducerContext) {
    for person in ctx.db.person().iter() {
        log::info!("Hello, {}!", person.name);
    }
    log::info!("Hello, World!");
}
