<template>
    <div class="container">
      <button @click="handleClick" class="avatar-button">
        <img :src="imageUrl" alt="Avatar" class="avatar-image" />
      </button>
    </div>
</template>
  
<script>
  export default {
    props: {
      imageFileName: String,
    },
    data() {
      return {
        clickCount: 0,
      };
    },
    computed: {
      imageUrl() {
        return require("@/assets/" + this.imageFileName);
      },
    },
    methods: {
      handleClick() {
        this.clickCount++;
        console.log("AvarButton clicked. Click count:", this.clickCount);
      },
    },
  };
</script>
  
<style scoped>
  .container {
    position: fixed;
    top: 0;
    right: 500px;
    display: flex;
    justify-content: flex-end;
    align-items: flex-start;
    height: 100vh;
    padding: 0;
    }

.avatar-button {
    width: 60px;
    height: 90px;
    display: flex;
    justify-content: center;
    align-items: center;
    border: none;
    background-color: lightgray;
    padding: 0;
}
  
  .avatar-image {
    max-width: 100%;
    max-height: auto;
  }
</style>