import { connectDB } from "@/util/database.js";
import Link from "next/link";
import ListItem from "./ListItem";

export default async function List() {

   const client = await connectDB;
   const db = client.db("forum");
   let result = await db.collection('post').find().toArray();
   // console.log(result);

   return (
      <ListItem result={result}/>
   )
}
