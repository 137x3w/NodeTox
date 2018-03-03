import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem, ListItemText } from 'material-ui/List';
import Typography from 'material-ui/Typography';
import Button from 'material-ui/Button';
import Modal from 'material-ui/Modal';
import Card, { CardActions, CardMedia } from 'material-ui/Card';

const styles = theme => ({
  primaryText: {
    flex: 1,
    cursor: 'pointer',
  },
  toxAddressQrCodeViewerModal: {
    position: 'absolute',
    backgroundColor: theme.palette.background.paper,
    top: 'calc(50% - 100px)',
    left: 'calc(50% - 100px)',
    width: '200px',
    height: '200px',
  },
  qrCodeImage: {
    height: '200px',
  }
});

class ToxAddress extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;

    this.state = {
      toxAddressQrCodeModalOpened: false,
    }

    this.openToxAddressQrCodeViewer = this.openToxAddressQrCodeViewer.bind(this);
    this.handleCloseToxAddressQrCodeViewer = this.handleCloseToxAddressQrCodeViewer.bind(this);
  }

  openToxAddressQrCodeViewer = function() {
    this.setState({
      toxAddressQrCodeModalOpened: true,
    });    
  }

  handleCloseToxAddressQrCodeViewer = function() {
    this.setState({
      toxAddressQrCodeModalOpened: false,
    });
  }

  render() {
    return (
      <ListItem>
        <ListItemText 
          disableTypography
          primary={
            <Typography noWrap variant="subheading" 
              className={ this.classes.primaryText }
            >
              { this.props.toxAddress }
            </Typography>
          }
          secondary={
            <Typography noWrap variant="caption">
              Tox address
            </Typography>
          }
        />
        <Button
          onClick={ this.openToxAddressQrCodeViewer }
        >
          QR Code
        </Button>

        <Modal
          open={ this.state.toxAddressQrCodeModalOpened }
          onClose={ this.handleCloseToxAddressQrCodeViewer }
        >
          <div className={ this.classes.toxAddressQrCodeViewerModal }>
            <Card>
              <CardMedia
                className={ this.classes.qrCodeImage }
                image={ this.props.toxAddressQrCode }
              />
            </Card>
          </div>
        </Modal>
        
      </ListItem>
    );
  }
}

ToxAddress.propTypes = {
  classes: PropTypes.object.isRequired,
  toxaddress: PropTypes.string,
};

ToxAddress.defaultProps = {
  toxAddress: "",
  toxAddressQrCode: "",
}

export default withStyles(styles)(ToxAddress);