# boiler

Boiler plate for Revery libraries/projects.

### Commands

- `esy` - (shorthand for `esy install && esy build`)
- `esy test` - run tests
- `esy example` - launches the example app
- `esy @test` and `esy @example` when the corresponding command is "missing a lock, run esy install"

### Notes:

- `override.install` is necessary to make "test" recognized in: `esy '@test' x test`
