// ===========  GLOBAL ============ //
var name = "Select";
var job = "";
var position = "Current position";

// -----------  CATEGORY JSON ------------ //
var categories = [
	{ catName: "Web Development", catPosition: "Open position", catJob: "354" },
	{
		catName: "Education & Training",
		catPosition: "Close position",
		catJob: "100"
	},
	{ catName: "PHP Programming", catPosition: "Open position", catJob: "400" },
	{ catName: "Web Designer", catPosition: "Open position", catJob: "354" },
	{ catName: "Graphic Designer", catPosition: "Open position", catJob: "143" },
	{ catName: "English", catPosition: "Open position", catJob: "200" },
	{
		catName: "Project Management",
		catPosition: "Open position",
		catJob: "100"
	},
	{ catName: "Customer Service", catPosition: "Open position", catJob: "564" },
	{ catName: "Multimedia", catPosition: "Open position", catJob: "354" },
	{ catName: "Social Media", catPosition: "Open position", catJob: "300" },
	{ catName: "Finance Management", catPosition: "Open position", catJob: "22" },
	{ catName: "Marketing & Sales", catPosition: "Open position", catJob: "354" },
	{ catName: "Advertising", catPosition: "Open position", catJob: "90" },
	{ catName: "Writing", catPosition: "Open position", catJob: "150" },
	{ catName: "Office & Admin", catPosition: "Open position", catJob: "123" },
	{
		catName: "Software Development",
		catPosition: "Open position",
		catJob: "452"
	}
];

// ===========  DOCUMENT READY ============ //
$(document).ready(function() {
	displaySelected();
	for (cat in categories) {
		var options =
			'<option class="cat-name">' + categories[cat].catName + "</option>";
		$("#name-selector").append(options);
	}
	function display() {
		var catTitle = "<a href=#><h6>" + categories[cat].catName + "</h6></a>";
		var catJob = "<label>" + categories[cat].catJob + "</label>";
		var catPosition = "&nbsp;<span>" + categories[cat].catPosition + "</span>";
		var category = "<li>" + catTitle + catJob + catPosition + "</li>";
		$(".category-list").append(category);
	}
	function displaySelected() {
		$(".category-list").empty();
		for (cat in categories) {
			if (
				(name == categories[cat].catName || name == "Select") &&
				(job == categories[cat].catJob || job == "") &&
				(position == categories[cat].catPosition ||
					position == "Current position")
			) {
				display();
			}
		}
	}
	$("#name-selector").change(function() {
		$("#name-selector option:selected").each(function() {
			name = this.text;
			displaySelected();
		});
	});

	$("#job-selector").change(function() {
		job = $(this).val();
		displaySelected();
	});

	$("#position-selector").change(function() {
		$("#position-selector option:selected").each(function() {
			position = this.text;
			displaySelected();
		});
	});

	display;
});
