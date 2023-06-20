// here we return two elements : "table" and div with class "main"
const main_list = document.querySelector("table");
const main_div = document.querySelector(".main");

// here we heve a list of our movie's api
const movies_list = [
  "https://swapi.dev/api/films/1",
  "https://swapi.dev/api/films/2",
  "https://swapi.dev/api/films/3",
  "https://swapi.dev/api/films/4",
  "https://swapi.dev/api/films/5",
  "https://swapi.dev/api/films/6",
];

// here we use promise.all to fetch all the data together and return them at the same time.
Promise.all([
  get_movies_data(movies_list[0]),
  get_movies_data(movies_list[1]),
  get_movies_data(movies_list[2]),
  get_movies_data(movies_list[3]),
  get_movies_data(movies_list[4]),
  get_movies_data(movies_list[5]),
]).then((value) => {
  // use forEach method to iterate on each value of our fetching
  value.forEach((item) => {
    const new_row = document.createElement("tr"); // create new tr element
    new_row.classList.add("align"); // add a class called "align" to change the text alignment
    item.forEach((res, index) => {
      if (index === 3) {
        // forth index of each item is StarShips part
        const new_a = document.createElement("button");
        const text = document.createTextNode("StarShips");
        new_a.appendChild(text); //append the text to our button
        new_a.type = "button";
        new_row.appendChild(new_a);
      } else {
        // else index is 0,1 or 2 we should show the data aabout the movie
        const new_td = document.createElement("td");
        const text = document.createTextNode(res);
        new_td.appendChild(text);
        new_row.appendChild(new_td);
      }
    });
    main_list.appendChild(new_row);
  });

  const btns = document.querySelectorAll("button");
  btns.forEach((item, index) => {
    // set an event for each StarShip's buttons
    item.addEventListener("click", () => {
      let range = 0;
      const movie = value[index];
      const ss_count = movie[3].length;
      const ss_new = document.createElement("div");
      const ss_h = document.createElement("h1");
      const btn_div = document.createElement("div");
      btn_div.classList.add("btn_div");
      // create next , pre, back buttons to manage the StarShips's list
      const next = document.createElement("button");
      const pre = document.createElement("button");
      const back = document.createElement("button");
      next.innerText = "next";
      pre.innerText = "pre";
      back.innerText = "back";
      next.classList.add("button_");
      pre.classList.add("button_");
      back.classList.add("button_");
      ss_h.innerHTML = movie[0];
      const ss_ul = document.createElement("ul");
      // manage to how show the StarShips list in a page.
      movie[3].forEach(async (item, index) => {
        if (index < 10) {
          const ss_li = document.createElement("li");
          const ss_details = await fetch(item);
          const ss_name = await ss_details.json();
          ss_li.innerHTML = ss_name.name;
          ss_ul.appendChild(ss_li);
        }
      });
      btn_div.appendChild(next);
      btn_div.appendChild(pre);
      btn_div.appendChild(back);
      ss_new.appendChild(btn_div);
      ss_new.appendChild(ss_h);
      ss_new.appendChild(ss_ul);
      main_div.replaceChild(ss_new, main_list);
      back.addEventListener("click", () => {
        window.location.href = "./index.html"; // when click on back we redirect to index.html.
      });
      next.addEventListener("click", () => {
        range++;
        if (range <= Math.floor(ss_count / 10)) {
          ss_ul.innerHTML = "";
          movie[3].forEach(async (item, index) => {
            // here when click on next , we show other 10 StarShips
            if (range * 9 <= index && index <= (range + 1) * 9) {
              console.log("index in if is : " + index);
              const ss_li = document.createElement("li");
              const ss_details = await fetch(item);
              const ss_name = await ss_details.json();
              ss_li.innerHTML = ss_name.name;
              ss_ul.appendChild(ss_li);
            }
          });
          ss_new.replaceChild(ss_ul, ss_ul);
        } else {
          range = Math.floor(ss_count / 10);
        }
      });
      pre.addEventListener("click", () => {
        range--;
        if (range >= 0) {
          ss_ul.innerHTML = "";
          movie[3].forEach(async (item, index) => {
            // here when click on pre , we show previous 10 StarShips
            if (range * 9 <= index && index <= (range + 1) * 9) {
              console.log("index in if is : " + index);
              const ss_li = document.createElement("li");
              const ss_details = await fetch(item);
              const ss_name = await ss_details.json();
              ss_li.innerHTML = ss_name.name;
              ss_ul.appendChild(ss_li);
            }
          });
          console.log(ss_ul);
          ss_new.replaceChild(ss_ul, ss_ul);
        } else {
          range = 0;
        }
      });
    });
  });
});

// in this function we fetch the data and return the title , episode_id , release_data and StarShips of the movies.
async function get_movies_data(url) {
  const movie_details = await fetch(url);
  const movie_data = await movie_details.json();
  console.log(movie_data);
  return [
    movie_data.title,
    movie_data.episode_id,
    movie_data.release_date,
    movie_data.starships,
  ];
}
