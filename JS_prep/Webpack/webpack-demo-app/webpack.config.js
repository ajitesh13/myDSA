const path = require('path');

module.exports = {
    // mode: 'development',
    // devtool: 'none', // commenting this line will make webpack use eval 
    // entry: "./src/index.js", // this is for single entry point
    entry: { // multiple entry points 
        min: "./src/index.js",
        vendor: "./src/vendor.js"
    },
    // output: {
    //     filename: "main.js",
    //     path: path.resolve(__dirname, "dist")
    // },
    module: {
        rules: [
            {
                test: /\.html$/,
                use: ["html-loader"]
            },
            {
                test: /\.(svg|png|jpg|gif)$/,
                use: {
                    loader: "file-loader",
                    options: {
                        name: "[name].[hash].[ext]",
                        outputPath: "imgs"
                    }
                }
            }
        ]
    },
}