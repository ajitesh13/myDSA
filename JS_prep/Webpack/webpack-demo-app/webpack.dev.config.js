const path = require('path');
const merge = require('webpack-merge');
const common = require('./webpack.config');
var HtmlWebPackPlugin = require('html-webpack-plugin');

module.exports = merge(common, {
    mode: 'development',
    // devtool: 'none', // commenting this line will make webpack use eval 
    output: {
        filename: "[name].bundle.js",
        path: path.resolve(__dirname, "dist")
    },
    module: {
        rules: [
            {
                test: /\.scss$/,
                use: [
                    "style-loader", // 3. Inject styles into DOM 
                    "css-loader", // 2. Turns css into commonjs 
                    "sass-loader" // 1. Turns sass into css
                ] // order is important
            }
        ]
    },
    plugins: [
        new HtmlWebPackPlugin({
            template: "./src/template.html"
        })
    ]
});