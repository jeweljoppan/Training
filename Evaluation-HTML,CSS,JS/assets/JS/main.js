// ===========  GLOBAL ============ //

// -----------  CATEGORY JSON ------------ //
var newsData = [
	{
		newsImage: "assets/img/news-img-001.jpg",
		newsTitle: "Independent apartment with mordern design",
		newsAuthor: "Admin",
		newsDate: "JANUARY 16, 2018"
	},
	{
		newsImage: "assets/img/news-img-002.jpg",
		newsTitle: "Mordern apartment adjacent to eco park",
		newsAuthor: "Admin",
		newsDate: "JANUARY 16, 2018"
	},
	{
		newsImage: "assets/img/news-img-003.jpg",
		newsTitle: "We're doing business with pleasure",
		newsAuthor: "Admin",
		newsDate: "JANUARY 16, 2018"
	}
];

// ===========  DOCUMENT READY ============ //
$(function() {
	$("#footer").load("footer.html");
	$("#navbarRest").load("navbar.html #loadPoint");
	newsDisplay();
	function newsDisplay() {
		for (data in newsData) {
			var newImage =
				'<img class="padding-img image" src="' +
				newsData[data].newsImage +
				'" width="300px" height="300px">';

			var newTitle =
				'<a href="./error.html"><h4 class="news-title">' +
				newsData[data].newsTitle +
				"</h4></a>";
			var newCaption =
				"<p> BY&nbsp<label>" +
				newsData[data].newsAuthor +
				"</label>&nbsp&nbsp|&nbsp&nbsp" +
				newsData[data].newsDate +
				"</p>";
			var newContent =
				'<div class="col-4 p-2 each-news">' +
				newImage +
				newCaption +
				newTitle +
				"</div>";
			$("#news-content").append(newContent);
		}
	}
});
