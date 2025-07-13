# boxbox
functional programming on all layers

execute on remote

UX: write one script to specify app behavior for:
  - client
  - backend:
    - server
    - database


```

# *********** backend code ***********

import boxbox

boxbox.set_url("boxbox.com")

def meep():
  pass

def api():
  pass


# *********** client code ***********

def login(username:string, password:string) -> boxbox.user:
  return boxbox.login(username, password)

def signup(username:string, password:string) -> boxbox.user:
  return boxbox.signup(username, password)

def change_password(user:boxbox.user, new_password:string):
  boxbox.set_secret(user, "password", new_password)

def set_status(user:boxbox.user, status:string): 
  boxbox.set_public(user, "status", status)

def get_status(user:boxbox.user) -> string:
  boxbox.get_public(user, "status")

```


## boxbox API

### connect(url:string) -> server
connect to boxbox server

### server.login(username:string, password:string) -> connection
login to boxbox server

### server.signup(username:string, password:string) -> connection
signup to boxbox server

### connection.set_secret(key:string, value:string) -> void
existence and value are secret.

### connection.set_public(key:string, value:string) -> void
public data

### connection.get_secret(key:string) -> string
get YOUR secret data

### connection.get_public(key:string, owner:string) -> string
get public data of another user


### connection.publish< X, Y>(key:string, value:X->Y) -> void

