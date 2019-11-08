// ===========  GLOBAL ============ //


// -----------  CATEGORY JSON ------------ //

var categoryList = [    {   categoryTitle: "Web Development", 
                            categoryDescription: "Open Position", 
                            categoryCount: "654" },
                        {   categoryTitle: "App Development", 
                            categoryDescription: "Open Position", 
                            categoryCount: "354" },
                        {   categoryTitle: "Web Development", 
                            categoryDescription: "Closed Position", 
                            categoryCount: "154" },
                        {   categoryTitle: "Web Design", 
                            categoryDescription: "Open Position", 
                            categoryCount: "354" },
                        {   categoryTitle: "App Development", 
                            categoryDescription: "Closed Position", 
                            categoryCount: "354" },
                        {   categoryTitle: "App Development", 
                            categoryDescription: "Open Position", 
                            categoryCount: "254" },
                        {   categoryTitle: "Web Development", 
                            categoryDescription: "Open Position", 
                            categoryCount: "354" },
                        {   categoryTitle: "Web Development", 
                            categoryDescription: "Closed Position", 
                            categoryCount: "354" },
                        {   categoryTitle: "Web Development", 
                            categoryDescription: "Closed Position", 
                            categoryCount: "354" },
                        {   categoryTitle: "Web Development", 
                            categoryDescription: "Closed Position", 
                            categoryCount: "254" },
                        {   categoryTitle: "Web Development", 
                            categoryDescription: "Open Position", 
                            categoryCount: "554" },
                        {   categoryTitle: "App Development", 
                            categoryDescription: "Open Position", 
                            categoryCount: "254" },
                        {   categoryTitle: "App Development", 
                            categoryDescription: "Open Position", 
                            categoryCount: "154" },
                        {   categoryTitle: "Web Design", 
                            categoryDescription: "Closed Position", 
                            categoryCount: "354" },
                        {   categoryTitle: "Web Design", 
                            categoryDescription: "Open Position", 
                            categoryCount: "354" },
                        {   categoryTitle: "Web Development", 
                            categoryDescription: "Open Position", 
                            categoryCount: "654" }
                    ];

// ===========  DOCUMENT READY ============ //

$(document).ready(function(){
    
    for(var catItem = 0; catItem < categoryList.length; catItem++){
        var catListItemTitle = '<a href="#"><h3>'+ categoryList[catItem].categoryTitle +'</h3></a>';
        var catListItemDescription = '<h4><span>'+ categoryList[catItem].categoryCount +'</span>' + categoryList[catItem].categoryDescription+ '</h4>';
        var catListItem = '<li>' + catListItemTitle + catListItemDescription + '</li>';         
        $(".category-list").append(catListItem);
    }

});