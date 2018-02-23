import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Paper from 'material-ui/Paper';
import Grid from 'material-ui/Grid';
import List, {
  ListItem,
  ListItemAvatar,
  ListItemIcon,
  ListItemSecondaryAction,
  ListItemText,
} from 'material-ui/List';
import AppBar from 'material-ui/AppBar';
import Card, { CardHeader, CardMedia, CardContent, CardActions } from 'material-ui/Card';
import Toolbar from 'material-ui/Toolbar';
import TextField from 'material-ui/TextField';
import Typography from 'material-ui/Typography';
import Avatar from 'material-ui/Avatar';
import Badge from 'material-ui/Badge';
import Icon from 'material-ui/Icon';
import FaceIcon from 'material-ui-icons/Face';
import VideoCallIcon from 'material-ui-icons/VideoCall';
import IconButton from 'material-ui/IconButton';
import FolderIcon from 'material-ui-icons/Folder';
import DeleteIcon from 'material-ui-icons/Delete';
import SendIcon from 'material-ui-icons/Send';
import MoreVertIcon from 'material-ui-icons/MoreVert';
import Divider from 'material-ui/Divider';
import { FormControl, FormHelperText } from 'material-ui/Form';
import Input, { InputLabel, InputAdornment } from 'material-ui/Input';
import Visibility from 'material-ui-icons/Visibility';
import VisibilityOff from 'material-ui-icons/VisibilityOff';
import classnames from 'classnames';
import 'typeface-roboto';

const styles = theme => ({
  root: {
    
  },
  sideBar: {
    backgroundColor: "green",
    padding: '0px !important',
    overflow: 'hidden',
    height: '100vh',
  },
  mainView: {
    backgroundColor: "blue",
    padding: '0px !important',
    height: '100vh',
  },
  profile: {
    overflow: 'hidden',
    minHeight: '120px',
    padding: '10px',
    backgroundColor: "red",
  },
  contactList: {
    overflowY: 'auto',
    height: '70vh',
    padding: 0,
  },
  contactListItem: {
    height: '14vh',
  },
  profileAvatar: {
    width: '50px',
    height: '50px',
  },
  selfProfileAvatar: {
    margin: '10px',
  },
  chatProfileAvatar: {
    padding: '10px',
  },
  chatBar: {
    backgroundColor: "yellow",
  },
  chatArea: {
    backgroundColor: "gray",
    height: 'calc(100% - 153px)',
  },
  chatTextBox: {
    backgroundColor: "orange",
    // height: '80px',
    padding: '15px',
  },
});

function generate(element) {
  return [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10].map(value =>
    React.cloneElement(element, {
      key: value,
    }),
  );
}

function FullWidthGrid(props) {
  const { classes } = props;

  return (
    <div className={classes.root}>
      <Grid container>
        <Grid item xs={4} className={classes.sideBar}>
          <Grid item align="center" direction="column" className={classes.profile}>
            <Grid item>
              <Avatar className={classnames(classes.profileAvatar, classes.selfProfileAvatar)}>
                <FolderIcon/>
              </Avatar>
            </Grid>
            <Grid item xs={10}>
              <Typography align="center" noWrap gutterBottom style={{fontWeight: 500}}>
                dratuti
              </Typography>
            </Grid>
            <Grid item xs={10}>
              <Typography variant="caption" align="center" noWrap gutterBottom style={{fontWeight: 500}}>
                ававвввввввввввввввввввввва
              </Typography>
            </Grid>
          </Grid>
          <Grid item>
            <List className={classes.contactList}>
              {generate(
                <ListItem button className={classes.contactListItem}>
                  <ListItemAvatar>
                    <Avatar className={classes.profileAvatar}>
                      <FolderIcon />
                    </Avatar>
                  </ListItemAvatar>
                  <ListItemText primary="Single-line item" secondary="test"/>
                </ListItem>
              )}
            </List>
          </Grid>
        </Grid>
        <Grid item xs={8} className={classes.mainView}>
          <Grid item className={classes.chatBar}>
            <CardHeader
              avatar={
                <Avatar>
                  <FolderIcon/>
                </Avatar>
              }
              action={
                <IconButton>
                  <MoreVertIcon/>
                </IconButton>
              }
              title="Shrimp and Chorizo Paella"
            />
          </Grid>
          <Grid item className={classes.chatArea}>
          </Grid>
          <Grid item alignItems="center" className={classes.chatTextBox}>
            <Input multiline fullWidth rows="2" endAdornment={
              <InputAdornment position="end">
                  <IconButton color="primary" aria-label="Smiles">
                    <FaceIcon/>
                  </IconButton>
                  <IconButton color="primary" aria-label="Send">
                    <SendIcon/>
                  </IconButton>
                </InputAdornment>
              }
            />
          </Grid>
        </Grid>
      </Grid>
    </div>
  );
}

FullWidthGrid.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(FullWidthGrid);
