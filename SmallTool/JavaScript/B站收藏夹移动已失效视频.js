function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

async function move() {
  const t = setInterval(async function() {
    $("li.small-item.disabled").find(".video-check-container").click();
    $(".fav-action-fixtop > ul:nth-child(1) > li:nth-child(4)").click();
    // sleep(500);
    await sleep(1000);
    $("li.target-favitem:nth-child(10)").click(); // replace the number you want
    $("div.modal-container:nth-child(2) > div:nth-child(2) > div:nth-child(1) > div:nth-child(3) > a:nth-child(1) > span:nth-child(1)").click();
    await sleep(1000);
  }, 1300)
}

move();
