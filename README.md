

# BoxBox Project

## starting out:
SpaceTimeDB is a project that allows you to define a backend and database in a single RUST file.
You then just upload it to the spacetime url and they create a seamless server for you.
BoxBox wants to extend that idea to create a full webapp in a single high level file.
Users can generate new logic on the fly and pay for compute on the go.


## BoxBox core idea:

objects of concern:
  - computer
  - user
  - data
  - compute

assume
  - every computer `has` an url
  - every user `has` credit
  - compute costs credit
  - user knows key

boxbox

  - account
    - id/key
    - credit
  - store secret data
  - publish data
  - publish functions
    - function is callable publicly
    - receives caller id
    - acts with full creator permissions
    - code is visible
  - call other peoples functions
    - controlled pay for compute


## Dev Experience

Write a single file, our cli scripts extracts backend and frontend code, compiles them and puts uploads everything.

## Language

what High Level Language should BoxBox use?

High level actually usable language

probably functional language without global state (this is needed so we can chop up the file into frontend and backend code)

needs to run on frontend and inside rust meaning either:
  - compiles to wasm
  - compiles to js and is something that runs inside RUST

has to be secure

preferably fast

supports tiny compiled functions for the backend

## candidates (not final)

- rust
  problem: rust is actually not functional although maybe close enough?
  how would you chop up the file into frontend and backend code?

