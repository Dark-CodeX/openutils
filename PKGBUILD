pkgname="openutils-chunkio"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="CHUNKIO : The Performant I/O Library"
arch=("x86_64" "i686")
conflicts=('openutils-chunkio')
depends=(gcc)
license=("GNU GPL v3.0")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/chunkio/main/chunkio/chunkio_bytes_reader.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/chunkio/main/chunkio/chunkio_lines_reader.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/chunkio/main/chunkio/chunkio_writer.hh")

sha512sums=(
	"cb1a053942d54d2df79abd922e88d81f788836bef124336d526166b172bf424bfed3da309bc0d7d471acc1ebed6d0a17445a265ea18a3ef0392c4c73982c4834"
	"ac0b90d6a91881880fe7299eb5786ba9f6717ebf2deff31a9406a6d922d2d501dd98cc4d0d9c2b04480776105cb7bbf2f792348aef84553514f2b8418d73da1a"
	"0a991bf3105cdf8c444dba0ad3ac20aa32de8aa4024a769e29182ff439cd8c3dec6cb641bfeb28718780dc133d3dcddd28744205e42dd785f5dbe1f6e960ced0")

package() {
	echo "CHUNKIO : The Performant I/O Library"
	mkdir -p "${pkgdir}/usr/include/openutils/chunkio"
	cp "${srcdir}/chunkio_bytes_reader.hh" "${pkgdir}/usr/include/openutils/chunkio/chunkio_bytes_reader.hh"
	cp "${srcdir}/chunkio_lines_reader.hh" "${pkgdir}/usr/include/openutils/chunkio/chunkio_lines_reader.hh"
	cp "${srcdir}/chunkio_writer.hh" "${pkgdir}/usr/include/openutils/chunkio/chunkio_writer.hh"
	echo "Done!"
}
