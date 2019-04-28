if (typeof(Module) === "undefined") Module = {};
Module["arguments"] = ["/bigfile"];
Module["preInit"] = function() {
  FS.createLazyFile('/', "bigfile", "/in.mp4", true, false);
};
var doTrace = true;
Module["print"] =    function(s) { self.postMessage({channel: "stdout", line: s}); };
Module["stderr"] =   function(s) { self.postMessage({channel: "stderr", char: s, trace: ((doTrace && s === 10) ? new Error().stack : null)}); doTrace = false; };
