open TestFramework;

describe("Example", ({test}) => {
  test("1", ({expect}) => {
    let actual = [1];
    expect.list(actual).toEqual([1]);
  });

  test("2", ({expect}) => {
    let actual = Boiler.x;
    expect.string(actual).toMatchSnapshot();
  });
});
