function restoreIpAddresses(s) {
    let result = [];
    let path = new Array(4);

    function backtrack(start, part) {
      
        if (part === 4) {
            if (start === s.length) {
                result.push(path.join('.'));
            }
            return;
        }

      
        for (let len = 1; len <= 3; len++) {
            if (start + len > s.length) break;

            let segment = s.substring(start, start + len);
            let num = parseInt(segment);

          
            if (num > 255 || (segment.length > 1 && segment[0] === '0')) continue;

            path[part] = segment;
            backtrack(start + len, part + 1);
        }
    }

    backtrack(0, 0);
    return result;
}


let inputs = ["25525511135", "0000", "101023"];

inputs.forEach(input => {
    console.log(`Valid IPs for "${input}":`, restoreIpAddresses(input));
});
