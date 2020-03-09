open Revery;
open Revery.UI;
open Revery.UI.Components;

module Log = (val Timber.Log.withNamespace("Main"));

let outerContainer =
  Style.[
    backgroundColor(Color.hex("#515153")),
    position(`Absolute),
    flexDirection(`Row),
    alignItems(`Stretch),
    bottom(0),
    top(0),
    left(0),
    right(0),
  ];

let leftPanel =
  Style.[
    backgroundColor(Color.hex("#141313")),
    width(300),
    flexGrow(0),
    bottom(0),
    top(0),
    flexDirection(`Column),
    alignItems(`Stretch),
  ];

let rightPanel =
  Style.[
    backgroundColor(Color.hex("#363535")),
    flexGrow(1),
    bottom(0),
    top(0),
    padding(12),
  ];

let textStyle =
  Style.[
    color(Color.hex("#C87847")),
    fontFamily("Roboto-Regular.ttf"),
    fontSize(24.0),
  ];

let navButtonBase =
  Style.[
    height(60),
    flexGrow(0),
    marginHorizontal(4),
    marginVertical(2),
    paddingLeft(12),
    paddingTop(8),
    paddingRight(4),
    paddingBottom(4),
    Style.alignItems(`Center),
    flexDirection(`Row),
  ];

let navButtonInactive =
  navButtonBase @ Style.[backgroundColor(Color.hex("#252424"))];

let navButtonHover =
  navButtonBase @ Style.[backgroundColor(Color.hex("#363535"))];

let navButtonActive = navButtonHover @ Style.[marginRight(-4)];

module RightPane = {
  let make = () => {
    let text = Boiler.x;
    <View style=rightPanel> <Text style=textStyle text /> </View>;
  };
};

module NavButton = {
  let%component make = (~active=false, ~title, ~onClick, ()) => {
    let%hook (hover, setHover) = Hooks.state(false);
    let style =
      if (active) {
        navButtonActive;
      } else if (hover) {
        navButtonHover;
      } else {
        navButtonInactive;
      };
    let onMouseOver = _ => setHover(_ => true);
    let onMouseOut = _ => setHover(_ => false);
    <Clickable onClick>
      <View style onMouseOver onMouseOut>
        <Text style=textStyle text=title />
      </View>
    </Clickable>;
  };
};

let make = () => {
  let activeTab = 1;
  let onClick = _ => ();
  <View style=outerContainer>
    <View style=leftPanel>
      <NavButton active={activeTab === 1} title="One" onClick />
      <NavButton active={activeTab === 2} title="Two" onClick />
      <NavButton active={activeTab === 3} title="Three" onClick />
    </View>
    <RightPane />
  </View>;
};
