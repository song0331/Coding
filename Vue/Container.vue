<template>
   <div v-if="tabNum == 0">
      <div v-for="(item, i) in postData" :key="i">
         <Post :postData="postData" :num="i" :selFilter="selFilter" />
      </div>
   </div>

   <!-- 필터선택페이지 -->
   <div v-if="tabNum == 1">
      <div :class="`${selFilter} upload-image`" :style="`background-image:url(${imgURL})`"
      ></div>
      <div class="filters">
         <FilterBox v-for="(item, i) in filterData" :key="i" :filterName="item" :imgURL="imgURL">{{item}}</FilterBox>
      </div>
   </div>

   <!-- 글작성페이지 -->
   <div v-if="tabNum == 2">
      <div :class="`upload-image ${selFilter}`" :style="`background-image:url(${imgURL})`"
      ></div>
      <div class="write">
         <textarea v-model="text" class="write-box">{text}</textarea>
      </div>
      <div class="text-center mt-4">
         <p>Save하시고 상단에 발행을 눌러야 업로드 됩니다.</p>
         <button @click="posting" class="btn btn-outline-success">
            Save
         </button>
      </div>
   </div>

   <div v-if="tabNum == 3">
      <MyPage />
   </div>
</template>

<script>
import Post from "./Post.vue";
import FilterBox from "./FilterBox.vue";
import filterData from "./../assets/filterData.js";
import MyPage from "./MyPage.vue";

export default {
   name: "Container",
   data() {
      return {
         text: "write!!",
         uploadData: {},
         filterData : filterData,
      };
   },
   methods: {
      posting() {
         this.uploadData = {
            name: "Idol",
            userImage: this.imgURL,
            postImage: this.imgURL,
            likes: 324,
            date: "March 24",
            liked: false,
            content: this.text,
            filter: this.selFilter,
         };

         this.$emit('send', this.uploadData);
      },
   },
   components: {
      Post,
      FilterBox,
      MyPage,
   },
   props: {
      postData: Array,
      tabNum: Number,
      imgURL: String,
      selFilter: String,
   },
};
</script>

<style>
.upload-image {
   width: 100%;
   height: 450px;
   background: cornflowerblue;
   background-size: cover;
}
.filters {
   overflow-x: scroll;
   white-space: nowrap;
}
.filter-1 {
   width: 100px;
   height: 100px;
   background-color: cornflowerblue;
   margin: 10px 10px 10px auto;
   padding: 8px;
   display: inline-block;
   color: white;
   background-size: cover;
}
.filters::-webkit-scrollbar {
   height: 5px;
}
.filters::-webkit-scrollbar-track {
   background: #f1f1f1;
}
.filters::-webkit-scrollbar-thumb {
   background: #888;
   border-radius: 5px;
}
.filters::-webkit-scrollbar-thumb:hover {
   background: #555;
}
.write-box {
   border: none;
   width: 90%;
   height: 100px;
   padding: 15px;
   margin: auto;
   display: block;
   outline: none;
}
</style>