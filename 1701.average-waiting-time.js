/*
 * @lc app=leetcode id=1701 lang=javascript
 *
 * [1701] Average Waiting Time
 */

// @lc code=start
/**
 * @param {number[][]} customers
 * @return {number}
 */
var averageWaitingTime = function(customers) {


    let sum = 0;
    let last_time = 0;

    for (let i = 0; i < customers.length; i++) {

        if(last_time < customers[i][0]) {
            last_time = customers[i][0];
        }

        let now = last_time + customers[i][1] - customers[i][0];
        sum += now;
        last_time += customers[i][1]; 
        // console.log(last_time);
    }


    return (sum / customers.length);
    
};
// @lc code=end

