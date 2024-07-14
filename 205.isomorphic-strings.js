/*
 * @lc app=leetcode id=205 lang=javascript
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function (s, t) {

    if (s.length !== t.length) {
        return false;
    }

    let map = new Map();
    let set = new Set();
    for (let i = 0; i < s.length; i++) {
        if (map.has(s[i])) {
            if (map.get(s[i]) !== t[i]) {
                return false;
            }
        } else if (set.has(t[i])) {
            return false;
        } else {
            map.set(s[i], t[i]);
            set.add(t[i]);
        }
    }

    return true;
    
};
// @lc code=end

