let run = () => {
  let init = app => {
    Timber.App.enable();
    // Timber.App.setLevel(Timber.Level.debug);
    let window = Revery.App.createWindow(app, "Revery Example");
    let update = Revery.UI.start(window, <MainView />);
    let _ = update;
    ();
  };

  let _ = Revery.App.start(init);
  ();
};

run();
