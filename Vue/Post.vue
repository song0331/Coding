<template>
   <div class="post">
      <div class="post-header my-3">
         <div class="profile" :style="{background : `url(${postData[num].userImage})`}"></div>
         <span class="profile-name">{{postData[num].name}}</span>
      </div>
      <div @click="$store.commit('setLikes', num)" :class="`post-body ${postData[num].filter}`" :style="{background : `url(${postData[num].postImage})`, backgroundSize:'cover'}"></div>
      <div class="post-content">
         <p>{{$store.state.likes[num]}} Likes</p>
         <p><strong></strong> {{postData[num].content}}</p>
         <p class="date">{{postData[num].date}}</p>
      </div>
   </div>
</template>

<script>
export default {
   name:"Post",
   props:{
      postData:Array,
      num : Number,
      selFilter:String,
   }
};
</script>

<style>
.post {
   width: 100%;
}
.profile {
   background-image: url("https://placeimg.com/100/100/arch");
   width: 30px;
   height: 30px;
   background-size: 100%;
   border-radius: 50%;
   float: left;
}
.profile-name {
   display: block;
   float: left;
   padding-left: 10px;
   padding-top: 7px;
   font-size: 14px;
}
.post-header {
   height: 30px;
   padding: 10px;
}
.post-body {
   background-image: url("https://placeimg.com/640/480/animals");
   /* background-image: url("https://placeimg.com/640/480/animals"); */
   height: 450px;
   background-position: center;
   background-size: cover;
}
.post-content {
   padding-left: 15px;
   padding-right: 15px;
   font-size: 14px;
}
.date {
   font-size: 11px;
   color: grey;
   margin-top: -8px;
}
</style>