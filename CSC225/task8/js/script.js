$("form").submit(function (event) {
  event.preventDefault();
});

$(document).keypress(function (event) {
  if (event.which == 13) {
    $("#prepend").click();
  }
});
$("#prepend").click(function (event) {
  event.preventDefault();
  console.log("clicked");
  $("#alert-wrapper").html("");

  const tasks = $("#tasks");
  const input = $("#input").val();

  // validate
  const invalid = [];
  if (!input) {
    invalid.push("input");
  }
  if (invalid.length > 0) {
    const alerts = invalid.map(function (eventName) {
      return `<div class="alert alert-danger" role="alert">${eventName} is invalid</div>`;
    });
    $("#alert-wrapper").append(alerts);
    return;
  }
  // prepend
  tasks.prepend(`<p>${input}</p>`);
  $("#input").val("");
});
