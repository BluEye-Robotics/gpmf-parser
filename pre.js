if (typeof(Module) === "undefined") Module = {};
//Module["arguments"] = ["/bigfile"];
Module["preInit"] = function() {
  //FS.createLazyFile('/', "bigfile", "/in.mp4", true, false);
};

Module["print"] = function(s) { console.log(s); };
Module["stderr"] = function(s) { console.error(s); };

//Module["load"] = function(data) {
//  Module['FS_createDataFile']('/', 'video.mp4', data, true, true true);
//};
