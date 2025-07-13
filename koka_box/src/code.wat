(module
  (func $ff
    (param i32)
    (param i32)
    (result i32)
    (local.get 1)
    (local.get 1)
    i32.add
    return
    

  )
  (func $add
    (export "run")
    (param i32)
    (result i32)
    (result i32)
    (local i32)
    (local.get 0)
    (local.get 0)
    (local.get 0)
    i32.add
    (local.set 1)
    (local.get 1)
    (local.get 1)
    i32.add
    return
  )

)