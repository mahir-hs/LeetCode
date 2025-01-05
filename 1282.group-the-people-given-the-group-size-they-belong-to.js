/*
 * @lc app=leetcode id=1282 lang=javascript
 *
 * [1282] Group the People Given the Group Size They Belong To
 */

// @lc code=start
/**
 * @param {number[]} groupSizes
 * @return {number[][]}
 */
var groupThePeople = function(groupSizes) {
    const map = new Map();
    const arr = [];
    for (let i = 0; i < groupSizes.length; i++) {
        const size = groupSizes[i];
        if(!map.has(size)) {
            map.set(size, []);
        }
        const group = map.get(size); 
        group.push(i); 
        if (group.length === size) {
            arr.push(group);
            map.set(size, []); 
        }
    }
    return arr;
};
// @lc code=end

