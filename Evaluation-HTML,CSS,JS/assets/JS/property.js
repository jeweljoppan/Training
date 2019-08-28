// ===========  GLOBAL ============ //
var lastActive = "list";

//JSON object for property data
var propertyData = [
	{
		propertyImage: "assets/img/properties-001.jpg",
		propertyName: "Single House Near Orland Park,Chicago",
		propertyOwner: "Ghaly Marco",
		propertyType: ["APARTMENT,", "BAR,", "HOUSE"],
		propertyAddress: ["Orkland Park", "Chicago", "IL 60465", "USA"],
		propertyDescription:
			"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
		propertyPrice: "2.5",
		propertyNeed: ["RENT", "month"],
		featured: "true"
	},
	{
		propertyImage: "assets/img/properties-002.jpg",
		propertyName: "Apartment  Mordern 6035 W North Ave",
		propertyOwner: "Arafa El sherif",
		propertyType: ["APARTMENT,", "BAR,", "CAFE"],
		propertyAddress: ["8035 W North Ave", "Chicago IL", "", "USA"],
		propertyDescription:
			"Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. ",
		propertyPrice: "136020",
		propertyNeed: ["SALE", "range"],
		featured: "true"
	},
	{
		propertyImage: "assets/img/properties-003.jpg",
		propertyName: "155 Mercer St,New York",
		propertyOwner: "Arya Magady",
		propertyType: ["RESTAURANT,", "SPA,", "STORE"],
		propertyAddress: ["155 Mercer St", "New York", "NY 10012", "USA"],
		propertyDescription:
			"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
		propertyPrice: "5000",
		propertyNeed: ["RENT", "month"],
		featured: "true"
	},
	{
		propertyImage: "assets/img/properties-004.jpg",
		propertyName: "Restaurant 160 E 65th St",
		propertyOwner: "Arya Magdy",
		propertyType: ["FARM,", "RESTAURANT,", "SPA"],
		propertyAddress: ["160E 65th st", "New York", "NY 10025", "USA"],
		propertyDescription:
			"Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. ",
		propertyPrice: "1200000",
		propertyNeed: ["SALE", ""],
		featured: "true"
	},
	{
		propertyImage: "assets/img/properties-005.jpg",
		propertyName: "Villa 243 W 98th St",
		propertyOwner: "Arafa El sherif",
		propertyType: ["BAR,", "CAFE,", "VILLA"],
		propertyAddress: ["243W 98th St", "New York", "NY 10025", "USA"],
		propertyDescription:
			"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",

		propertyPrice: "480000",
		propertyNeed: ["SALE", ""],
		featured: "true"
	},
	{
		propertyImage: "assets/img/properties-006.jpg",
		propertyName: "Apartment 54 Morningside Dr Apt 52",
		propertyOwner: "Arafa El sherif",
		propertyType: ["APARTMENT,", "FARM,", "SPA"],
		propertyAddress: ["54 Morningside Dr", "New York", "NY 10025", "USA"],
		propertyDescription:
			"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",

		propertyPrice: "2000",
		propertyNeed: ["RENT", "month"],
		featured: "true"
	},
	{
		propertyImage: "assets/img/properties-007.jpg",
		propertyName: "Villa 40 Louise Ln, Chester",
		propertyOwner: "Sherief El Arafa",
		propertyType: ["APARTMENT,", "FARM,", "VILLA"],
		propertyAddress: ["40 Louise Ln", "Chester", "NY 10918", "USA"],
		propertyDescription:
			"Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.",
		propertyPrice: "5000000",
		propertyNeed: ["SALE", ""],
		featured: "true"
	},
	{
		propertyImage: "assets/img/properties-008.jpg",
		propertyName: "281 Ocean Terrace, Staten Island",
		propertyOwner: "Ghaly Marco",
		propertyType: ["HOUSE,", "RESTAURANT,", "SPA"],
		propertyAddress: ["281 Ocean Terrace", "Staten Isalnd", "NY 10301", "USA"],
		propertyDescription:
			"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
		propertyPrice: "3000000",
		propertyNeed: ["SALE", ""],
		featured: "true"
	},
	{
		propertyImage: "assets/img/properties-009.jpg",
		propertyName: "Villa in 629 East 83rd Street",
		propertyOwner: "Fatma Ghaly",
		propertyType: ["FARM,", "HOUSE,", "VILLA"],
		propertyAddress: ["629 E 83rd", "Los Angeles", "CA 900001", "USA"],
		propertyDescription:
			"Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.",
		propertyPrice: "1000",
		propertyNeed: ["RENT", "year"],
		featured: "true"
	}
];
$("#navbar").load("navbar.html #loadPoint");
$("#footer").load("footer.html");

// ===========  DOCUMENT READY ============ //
$(function() {
	displayAll();
	function displayAll() {
		for (data in propertyData) {
			display(propertyData[data]);
		}

	}
	function display(propertyData) {
		var propImage =
			'<img class="col-4 padding-img image" src="' +
			propertyData.propertyImage +
			'" width="250px" height="250px">';
		var propType = '<div class="type">';
		for (type in propertyData.propertyType) {
			propType +=
				'<label class="list-subtitle">' +
				propertyData.propertyType[type] +
				"&nbsp</label>";
		}
		propType += "</div>";
		var propTitle =
			'<a href="./error.html"><h4 class="list-title title">' +
			propertyData.propertyName +
			"</h4></a>";
		var propAddress =
			'<p class="list-text address">' +
			propertyData.propertyAddress[0] +
			", " +
			propertyData.propertyAddress[1] +
			", " +
			propertyData.propertyAddress[2] +
			", " +
			propertyData.propertyAddress[3] +
			"</p>";
		var propDesc =
			'<p class="list-text desc">' + propertyData.propertyDescription + "</p>";
		var propNeed =
			'<label class="col-6 list-green">FOR&nbsp' +
			propertyData.propertyNeed[0] +
			"</label>";
		var propPrice =
			'<label class="col-6 list-black">$' +
			propertyData.propertyPrice +
			"</label>";
		var content =
			'<div class="prop-object list-width row">' +
			propImage +
			'<div class="col-8 padding-content">' +
			propType +
			propTitle +
			propAddress +
			propDesc +
			'<div class="pt-lg-5">' +
			propNeed +
			propPrice +
			"</div></div></div>";
		$(".content").append(content);
	}

	$(".view").on("click", clickRegister);
	function clickRegister() {
		if ($(this).hasClass("grid")) {
			lastActive = "grid";
		}
		if ($(this).hasClass("list")) {
			lastActive = "list";
		}
		view();
	}
	function view() {
		if (lastActive == "grid") {
			$(".content")
				.removeClass("flex-column")
				.addClass("flex-row")
				.addClass("flex-wrap");
			$(".content .prop-object")
				.removeClass("list-width")
				.addClass("grid-width");
			$(".title").addClass("condense");
			$(".desc")
				.removeClass("d-inline-block")
				.addClass("d-none");
			$(".address").addClass("condense");
			$(".image")
				.removeClass("col-4")
				.addClass("col-12");
			$(".padding-content")
				.removeClass("col-8")
				.addClass("col-12");
		} else if (lastActive == "list") {
			$(".content")
				.removeClass("flex-row")
				.addClass("flex-column");
			$(".content .prop-object")
				.addClass("list-width")
				.removeClass("grid-width");
			$(".image")
				.removeClass("col-12")
				.addClass("col-4");
			$(".title").removeClass("condense");
			$(".desc").addClass("d-inline-block");
			$(".address").removeClass("condense");
			$(".padding-content")
				.addClass("col-8")
				.removeClass("col-12");
		}
	}

	$(".filter").on("click", function() {
		if ($(this).hasClass("rent")) {
			$(".content").empty();
			for (data in propertyData) {
				if (propertyData[data].propertyNeed[0] == "RENT") {
					display(propertyData[data]);
				}
			}
		}
		if ($(this).hasClass("sale")) {
			$(".content").empty();
			for (data in propertyData) {
				if (propertyData[data].propertyNeed[0] == "SALE") {
					display(propertyData[data]);
				}
			}
		}
		view();
	});
	$(".search").on("click", function() {
		var flag = 0;
		var label = $("#label-search").val();
		if (label == "All Labels") {
			displayAll();
		} else {
			label += ",";
			$(".content").empty();
			for (data in propertyData) {
				flag = 0;
				for (each in propertyData[data].propertyType) {
					if (
						label.toUpperCase() == propertyData[data].propertyType[each] &&
						flag == 0
					) {
						display(propertyData[data]);
						flag = 1;
					}
				}
			}
		}
		view();
	});
});
