# boiler

Boiler plate for Revery libraries/projects.

### Commands

- `esy` - (shorthand for `esy install && esy build`)
- `esy test` - run tests
- `esy example` - launches the example app
- `esy @test` and `esy @example` when the corresponding command is "missing a lock, run esy install"

### Notes:

- `override.install` is necessary to make "test" recognized in: `esy '@test' x test`
- `ocaml` is locked to `"<= 4.08.0"` in dev dependencies because that is the highest version supported by the VSCode extension I use
