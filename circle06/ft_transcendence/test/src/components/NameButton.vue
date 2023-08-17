<template>
    <div class="name-button">
      <button @click="handleClick" class="button">
        {{ userName }}
      </button>
    </div>
</template>
  
<script>
  export default {
    props: {
      userName: String,
    },
    data() {
      return {
        clickCount: 0,
      };
    },
    methods: {
      handleClick() {
        this.clickCount++;
        console.log("NameButton clicked. Click count:", this.clickCount);
      },
    },
  };
</script>
  
<style scoped>
  .name-button {
    position: fixed;
    top: 0;
    right: 320px;
    display: flex;
    justify-content: flex-end;
    align-items: flex-start;
    height: 100vh;
    padding: 0;
  }
  
  .button {
    width: 180px; /* 가로 크기를 AvatarButton의 3배로 설정 */
    height: 90px; /* 세로 크기는 AvatarButton과 동일하게 설정 */
    display: flex;
    justify-content: center;
    align-items: center;
    border: none;
    background-color: lightblue; /* 버튼 배경색을 변경 */
    padding: 0; /* 여백 제거 */
  }
</style>
  