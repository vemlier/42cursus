<template>
  <div id="app">
    <AvatarButton :imageFileName="avatarImageFileName" />
    <NameButton :userName="userName" />
  </div>
</template>

<script>
import AvatarButton from "@/components/AvatarButton.vue";
import NameButton from "@/components/NameButton.vue";

export default {
  components: {
    AvatarButton,
    NameButton,
  },
  data() {
    return {
      avatarImageFileName: "test.jpg",
      userName: "John Doe"
    };
  },
};
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
